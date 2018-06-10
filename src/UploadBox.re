
let onClick = (onUpload, (_)) => {
  let optionFile = Electron.showOpenDialog([|OpenFile|], [|("torrent", [|"torrent"|])|]);
  onUpload(optionFile);
};

let textCenterStyle = ReactDOMRe.Style.make(~textAlign="center", ());


let component = ReasonReact.statelessComponent("UploadBox");
let make = (~onUpload, ~path, _) => {
  ...component,
  render: (_) =>
    <Semantic.Card className="stretch-width">
      <div className="m20 upload__container" onClick=(onClick(onUpload))>
        <div className="upload__content">
          <div>
            <div style=(textCenterStyle)>
              <Semantic.Icon name="cloud download" className="icon-image" />
            </div>
            <div style=(textCenterStyle)> 
            (ReasonReact.stringToElement(
                switch (path) {
                | Some(uri) => uri
                | None =>"Drag n drop file"
                }
            ))
            </div>
          </div>
        </div>
      </div>
    </Semantic.Card>
};