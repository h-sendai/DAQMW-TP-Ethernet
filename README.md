# DAQ-Middleware Ethernetから読み出しスループットテスト

## ディレクトリ構成

```
/home/daq/DAQMW-TP-Ethernet/TPEtherReader
/home/daq/DAQMW-TP-Ethernet/TPEtherLogger
/home/daq/DAQMW-Latency/tp-ether-reader-logger.xml
```

## /etc/omniORB.cfgの設定

2MB以上のデータを送信するために/etc/omniORB.cfgに次の行を
追加する。

```
/etc/omniORB.cfg
# 8MB
giopMaxMsgSize = 8388608
```

## config.xml

tp-ether-reader-logger.xml中のパラメータ

```
<params>
    <param pid="bufsize_kb">128</param>
</params>
```

でTPEtherReaderCompが読むデータサイズを決める。

## 走らせ方

```
./go
```
