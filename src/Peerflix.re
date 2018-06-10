open Belt.Result;

let getFileList = (uri, callback) => {
  let args = ["peerflix", "-l", {j|"$uri"|j}];
  let join = (s1, s2) => s1 ++ " " ++ s2;
  let command = List.fold_left(join, "", args);
  ChildProcess.exec(command, result =>
    switch result {
    | Ok(x) =>
      callback(
        Ok(
          x
          |> AnsiStripper.strip
          |> Js.String.split("\n")
          |> Array.to_list
          |> List.map(x =>
               x |> Js.String.split(":") |> Array.map(Js.String.trim)
             )
          |> List.filter(x => Array.length(x) == 3)
          |> List.map(([|_, b, c|]) => (b, c))
        )
      )
    | Error(err) => callback(Error(err))
    }
  );
};