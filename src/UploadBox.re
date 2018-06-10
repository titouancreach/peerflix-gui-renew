let component = ReasonReact.statelessComponent("UploadBox");

let onClick = (onUpload, (_)) => {
  let optionFile = Electron.showOpenDialog([|OpenFile|], [|("torrent", [|"torrent"|])|]);
  onUpload(optionFile);
};


let make = (~onUpload, _) => {
  ...component,
  render: (_) =>
    <Semantic.Card className="stretch-width">
      <div className="m20 upload__container" onClick={onClick(onUpload)}>
        <div className="upload__content">
          <div>
            <div>
              <Semantic.Icon name="cloud download" className="icon-image" />
            </div>
            <div> (ReasonReact.stringToElement("Drag n drop file")) </div>
          </div>
        </div>
      </div>
    </Semantic.Card>
};