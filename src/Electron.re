
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

[@bs.module "electron"] [@bs.scope ("remote", "dialog")]
external rawShowOpenDialog: {. "properties": array(string), "filters": filterType} => 'a = "showOpenDialog";

let showOpenDialog = (dialogFlags, filters) => {
  let props = Array.map(flag_to_string, dialogFlags);
  let fltrs = Array.map(filter_to_js, filters);
  Js.log(fltrs);
  rawShowOpenDialog({"properties": props, "filters": fltrs});
};


