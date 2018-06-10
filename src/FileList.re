
let component = ReasonReact.statelessComponent("FileList");

let make = (~fileList, _) => {
  ...component,
  render: (_) => {
      Js.log(
          fileList |> 
          List.map(x => {
            let (name, size) = x;
            name;
        }) |> Array.of_list
      );


    <Semantic.Card className="stretch-width">
        ...(ReasonReact.createDomElement("ul", fileList |> List.map(x => {
            let (name, size) = x;
            <li>(ReasonReact.stringToElement(name ++ "(" ++ size ++")"))</li>
        }) |> Array.of_list))
    </Semantic.Card>
  }
};