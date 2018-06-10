let component = ReasonReact.statelessComponent("FileList");

let make = (~fileList, _) => {
  ...component,
  render: (_) => {
   <Semantic.Card className="stretch-width">
      <ul>
        (
          ReasonReact.arrayToElement(
            fileList
            |> List.map(x => {
                 let (name, size) = x;
                 <li key=name>
                   (ReasonReact.stringToElement(name ++ "  (" ++ size ++ ")"))
                 </li>;
               })
            |> Array.of_list
          )
        )
      </ul>
    </Semantic.Card>;
  }
};