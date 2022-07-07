# vial-keyboards  

git clone git@github.com:alvaromuente/vial-keyboards.git ~/qmk_firmware/keyboards/muente  
git -C ~/qmk_firmware/keyboards/muente pull

qmk list-keyboards | grep ^muente | while read keyboard ; do qmk compile -kb $keyboard -km all ; done

git clone git@github.com:alvaromuente/vial-keyboards.git ~/vial-qmk/keyboards/muente  
git -C ~/vial-qmk/keyboards/muente pull  

make muente/qs09:default  
make muente/qs09:vial  
