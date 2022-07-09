# vial-keyboards  
  
`git clone git@github.com:alvaromuente/vial-keyboards.git ~/qmk_firmware/keyboards/muente`  
`qmk list-keyboards | grep ^muente | while read keyboard ; do qmk compile -kb $keyboard -km default -e SILENT=true && qmk compile -kb $keyboard -km via -e SILENT=true ; done`  
  
`git clone git@github.com:alvaromuente/vial-keyboards.git ~/vial-qmk/keyboards/muente`  
`qmk list-keyboards | grep ^muente | while read keyboard ; do make $keyboard:default SILENT=true && make $keyboard:vial SILENT=true; done`  