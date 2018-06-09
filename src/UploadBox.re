let component = ReasonReact.statelessComponent("UploadBox");

let onClick = (_) =>
  Electron.showOpenDialog([|OpenFile|], [|("torrent", [|"torrent"|])|])
  |> ignore;

let make = (_) => {
  ...component,
  render: (_) =>
    <Semantic.Card className="stretch-width">
      <div className="m20 upload__container" onClick>
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