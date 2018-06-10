# peerflix-gui-renew
Rebuild an old project to test some new javascript frameworks

Compile Reason to JS  
  -> ```yarn run bsb -make-world ```  
(add -w to recompile on change)

Bundle javascript for electron  
  --> ```yarn run parcel --target="electron" --public-url="./" ./src/index.html```
