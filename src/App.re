open Belt.Result;

type state = {fileUrl: option(string), fileList: list((string, string))};

type action =
  | Upload(option(string))
  | FileList(list((string, string)));

let component = ReasonReact.reducerComponent("App");

let make = (_) => {
  ...component,
  initialState: () => {fileUrl: None, fileList: []},
  reducer: (action, state) =>
    switch action {
    | Upload(url) =>
      ReasonReact.UpdateWithSideEffects(
        {
            ...state,
            fileUrl: url
        },
        (
          ({send}) =>
            switch url {
            | None => ()
            | Some(url) => Peerflix.getFileList(url, result =>
                switch result {
                | Ok(s) => send(FileList(s))
                | Error(err) => Js.log("Err(" ++ err ++ ")")
                }
              );
            }
        )
      )
    | FileList(fileList) => ReasonReact.Update({...state, fileList: fileList})
    },
  render: ({send, state}) =>
    <div className="App">
      <UploadBox onUpload=(x => send(Upload(x))) path=state.fileUrl />
      <FileList fileList=state.fileList />
    </div>
};