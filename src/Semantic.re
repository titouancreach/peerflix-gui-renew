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
    external icon: ReasonReact.reactClass = "Icon";
    let make = (~name, ~className="", children) => 
      ReasonReact.wrapJsForReason(
          ~reactClass=icon,
          ~props={"name": name, "className": className},
          children
      );
};