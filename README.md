# vial-keyboards


git clone git@github.com:alvaromuente/vial-keyboards.git ~/qmk_firmware/keyboards/muente

qmk compile -kb muente/qs09 -km default
qmk compile -kb muente/qs09 -km via



git clone git@github.com:alvaromuente/vial-keyboards.git ~/vial-qmk/keyboards/muente

make muente/qs09:default
make muente/qs09:vial
