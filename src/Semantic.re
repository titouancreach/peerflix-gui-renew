module Button = {
  [@bs.module "semantic-ui-react"]
  external button : ReasonReact.reactClass = "Button";
  let make = (~onClick, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=button,
      ~props={"onClick": onClick},
      children
    );
};

module Card = {
  [@bs.module "semantic-ui-react"]
  external card : ReasonReact.reactClass = "Card";
  let make = (~className="", children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=card,
      ~props={"className": className},
      children
    );
};

module Image = {
  [@bs.module "semantic-ui-react"]
  external image : ReasonReact.reactClass = "Image";
  let make = (~src, ~bordered=false, ~className="", children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=image,
      ~props={"src": src, "bordered": bordered, "className": className},
      children
    );
};

module Icon = {
  [@bs.module "semantic-ui-react"]
  external icon : ReasonReact.reactClass = "Icon";
  let make = (~name, ~className="", children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=icon,
      ~props={"name": name, "className": className},
      children
    );
};

module List = {
  module Item = {
    [@bs.module "semantic-ui-react"] [@bs.scope "List"]
    external item : ReasonReact.reactClass = "Item";
    let make = children =>
      ReasonReact.wrapJsForReason(
        ~reactClass=item,
        ~props=Js.Obj.empty(),
        children
      );
  };
  module Content = {
    [@bs.module "semantic-ui-react"] [@bs.scope "List"]
    external content : ReasonReact.reactClass = "Content";
    let make = (~floated="left", children) =>
      ReasonReact.wrapJsForReason(
        ~reactClass=content,
        ~props={"floated": floated},
        children
      );
  };
  [@bs.module "semantic-ui-react"]
  external list : ReasonReact.reactClass = "List";
  let make = (~divided=false, ~verticalAlign="middle", ~style=ReactDOMRe.Style.make(), children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=list,
      ~props={"divided": divided, "verticalAlign": verticalAlign, "style": style},
      children
    );
};