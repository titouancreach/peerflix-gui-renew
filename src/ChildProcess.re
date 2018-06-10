open Belt.Result;

type command = string;
type error;

[@bs.deriving abstract]
type execOption = {
    [@bs.optional] timeout: int
};

[@bs.module "child_process"]
[@bs.val "exec"]
external nodeExec: (command, execOption, (error, string, string) => unit) => unit = "";


let exec = (~execOption=execOption(), command, callback) => {
    let cb = (callback, err, stdout, err) => 
        switch (err, stdout, err) {
        | (_, stdout, "") => callback(Ok(stdout))
        | (_, _, stderr) => callback(Error(stderr))
        };
    nodeExec(command, execOption, cb(callback));
}
