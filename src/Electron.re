
type flag = OpenFile | OpenDirectory | MultiSelections;

type filterType = array({. "name": string, "extensions": array(string)});

let flag_to_string = (flag) => 
  switch (flag) {
  | OpenFile => "openFile"
  | OpenDirectory => "openDirectory"
  | MultiSelections => "multiSelections" 
};

let filter_to_js = (filter) => {
  let (name, exts) = filter;
  {"name": name, "extensions": exts}
};

[@bs.module "electron"] [@bs.scope ("remote", "dialog")] [@bs.return nullable]
external rawShowOpenDialog: {. "properties": array(string), "filters": filterType} => option(array(string)) = "showOpenDialog";

let showOpenDialog = (dialogFlags, filters) => {
  let props = Array.map(flag_to_string, dialogFlags);
  let fltrs = Array.map(filter_to_js, filters);
  let optionFile = rawShowOpenDialog({"properties": props, "filters": fltrs});

  switch (optionFile) {
  | Some(files) => switch (Array.to_list(files)) {
    | [] => None
    | [x, ..._] => Some(x)
    }
  | None => None
  };
};


