let component = ReasonReact.statelessComponent("Lane");

let make = (~label, ~lane:Lane.lane, ~minValue, ~maxValue, ~onSetValue, ~onSetLength, ~onRandomiseAbsolute, _children) => {
  ...component,
  render: _self => {
    <div className="flex items-center">
      <p className="w4">{ReasonReact.string(label)}</p>
      <div className="w1" />
      <div className="flex">
        (ReasonReact.array(Array.mapi((i, value) =>
          <div key=(string_of_int(i)) className=("w2 relative " ++ (i > lane.loopAfterIndex ? "o-50" : ""))>
            <button
              disabled=(value === maxValue)
              className=("input-reset db w-100 h1 " ++ (lane.visualIndex === i ? "bg-red" : "bg-gray"))
              onClick=(_event => onSetValue(i, value + 1))
            />
            <button
              disabled=(value === minValue)
              className=("input-reset db w-100 h1 " ++ (lane.visualIndex === i ? "bg-red" : "bg-gray"))
              onClick=(_event => onSetValue(i, value - 1))
            />
            <p className="relative tc ma0">(ReasonReact.string(string_of_int(value)))</p>
            <button
              className="input-reset db w-100 h1"
              onClick=(_event => onSetLength(i))
            />
          </div>
        , lane.values)))
      </div>
      <div className="w1" />
      <div className="flex">
        <button onClick=(_event => onRandomiseAbsolute())>(ReasonReact.string("Random Absolute"))</button>
      </div>
    </div>
  }
};
