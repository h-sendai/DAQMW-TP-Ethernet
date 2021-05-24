#!/bin/sh

for i in {0..12}; do
    data_size=$((2**${i}))
    sed -e s"|%data_size%|$data_size|" tp-ether-reader-logger.xml.in > tp-ether-reader-logger-${data_size}kB.xml
done
