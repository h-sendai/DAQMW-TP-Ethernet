#!/bin/zsh

setopt extendedglob

do_run()
{
    local data_size
    local run_num
    rm -f /tmp/*.dat
    data_size=$1
    run_num=$2
    run.py -l tp-ether-reader-logger-${data_size}kB.xml
    sleep 5
    daqcom http://localhost/daqmw/scripts/ -c
    for r in {1..$run_num}; do
        echo "------> run $r"
        sleep 2
        daqcom http://localhost/daqmw/scripts/ -b $r
        sleep 30
        daqcom http://localhost/daqmw/scripts/ -e
        sleep 2
        #cp /tmp/*.dat log/${data_size}.${r}.dat
        #rm -f /tmp/*.dat
    done
    cp /tmp/daqmw/log.TPEtherLoggerComp log/run.${data_size}
    pkill -f Comp
}

for i in {0..12}; do
    data_size=$((2**${i}))
    echo "---> $data_size"
    do_run $data_size 3
done
