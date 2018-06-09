# peerflix-gui-renew
Rebuild an old project to test some new javascript frameworks

Compile Reason to JS 
  -> yarn run bsb -make-workd
(add -w to recompile on change)

Bundle javascript for electron
  --> yarn run parcel --targer="electron" --public-url="./" ./src/index.html
