let component = ReasonReact.statelessComponent("App");


let make = (_) => {...component, render: (_) => <div className="App"> <UploadBox /> </div>};