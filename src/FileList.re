let component = ReasonReact.statelessComponent("FileList");

let paddedContent = ReactDOMRe.Style.make(
    ~padding="20px", ());

let make = (~fileList, _) => {
  ...component,
  render: (_) => {
   <Semantic.Card className="stretch-width">
      <Semantic.List divided=true style=paddedContent>
        (
          ReasonReact.arrayToElement(
            fileList
            |> List.map(x => {
                 let (name, size) = x;
                 <Semantic.List.Item key=name>
                   <Semantic.List.Content>
                        (ReasonReact.stringToElement(name ++ "  (" ++ size ++ ")"))
                   </Semantic.List.Content>
                 </Semantic.List.Item>;
               })
            |> Array.of_list
          )
        )
      </Semantic.List>
    </Semantic.Card>;
  }
};