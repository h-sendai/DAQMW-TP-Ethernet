// -*- C++ -*-
/*!
 * @file 
 * @brief
 * @date
 * @author
 *
 */

#ifndef TPETHERREADER_H
#define TPETHERREADER_H

#include "DaqComponentBase.h"

#include <daqmw/Sock.h>

using namespace RTC;

class TPEtherReader
    : public DAQMW::DaqComponentBase
{
public:
    TPEtherReader(RTC::Manager* manager);
    ~TPEtherReader();

    // The initialize action (on CREATED->ALIVE transition)
    // former rtc_init_entry()
    virtual RTC::ReturnCode_t onInitialize();

    // The execution action that is invoked periodically
    // former rtc_active_do()
    virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

private:
    TimedOctetSeq          m_out_data;
    OutPort<TimedOctetSeq> m_OutPort;

private:
    int daq_dummy();
    int daq_configure();
    int daq_unconfigure();
    int daq_start();
    int daq_run();
    int daq_stop();
    int daq_pause();
    int daq_resume();

    int parse_params(::NVList* list);
    int read_data_from_detectors();
    int set_data(unsigned int data_byte_size);
    int write_OutPort();

    DAQMW::Sock* m_sock;               /// socket for data server

    //static const int EVENT_BYTE_SIZE  = 8;    // event byte size
    //static const int SEND_BUFFER_SIZE = 1024; //
    //unsigned char m_data[SEND_BUFFER_SIZE];
    unsigned char *m_data;
    int m_bufsize_kb;
    int m_bufsize;
    struct timeval m_tv_start;
    struct timeval m_tv_stop;
    unsigned int  m_recv_byte_size;

    BufferStatus m_out_status;

    int m_srcPort;                        /// Port No. of data server
    std::string m_srcAddr;                /// IP addr. of data server

    bool m_debug;
};


extern "C"
{
    void TPEtherReaderInit(RTC::Manager* manager);
};

#endif // TPETHERREADER_H
