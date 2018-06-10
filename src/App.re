
type state = {fileUrl: option(string)};

type action =
  | Upload(option(string));

let component = ReasonReact.reducerComponent("App");
let make = (_) => {
  ...component,
  initialState: () => {fileUrl: None},

  reducer: (action, _) =>
    switch action {
    | Upload(url) => {
            switch (url) {
            | Some(url) => Js.log("Some(" ++ url ++ ")")
            | None => Js.log("None")
            } |> ignore;
            ReasonReact.Update({fileUrl: url});
        }
    },


  render: (self) => 
    <div className="App"> 
        <UploadBox onUpload={x => self.send(Upload(x))} /> 
    </div>
};