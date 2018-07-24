[@bs.module "react-native"]
external view : ReasonReact.reactClass = "ActivityIndicator";

[@bs.module "react-native"] [@bs.scope "Platform"]
external _os : string = "OS";

let encodeSize = size =>
  switch (size) {
  | `small => Encode.string("small")
  | `large => Encode.string("large")
  | `exact(x) =>
    switch (_os) {
    | "ios" => Encode.string("small")
    | _ => Encode.int(x)
    }
  };

let make =
    (
      ~animating=?,
      ~color=?,
      ~size=?,
      ~hidesWhenStopped=?,
      ~accessibilityLabel=?,
      ~accessible=?,
      ~hitSlop=?,
      ~onAccessibilityTap=?,
      ~onLayout=?,
      ~onMagicTap=?,
      ~responderHandlers=?,
      ~pointerEvents=?,
      ~removeClippedSubviews=?,
      ~style=?,
      ~testID=?,
      ~accessibilityComponentType=?,
      ~accessibilityLiveRegion=?,
      ~collapsable=?,
      ~importantForAccessibility=?,
      ~needsOffscreenAlphaCompositing=?,
      ~renderToHardwareTextureAndroid=?,
      ~accessibilityTraits=?,
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "animating": fromOption(UtilsRN.optBoolToOptJsBoolean(animating)),
            "color": color,
            "size": fromOption(UtilsRN.option_map(encodeSize, size)),
            "hidesWhenStopped":
              fromOption(UtilsRN.optBoolToOptJsBoolean(hidesWhenStopped)),
          }
        ),
        ~accessibilityLabel?,
        ~accessible?,
        ~hitSlop?,
        ~onAccessibilityTap?,
        ~onLayout?,
        ~onMagicTap?,
        ~responderHandlers?,
        ~pointerEvents?,
        ~removeClippedSubviews?,
        ~style?,
        ~testID?,
        ~accessibilityComponentType?,
        ~accessibilityLiveRegion?,
        ~collapsable?,
        ~importantForAccessibility?,
        ~needsOffscreenAlphaCompositing?,
        ~renderToHardwareTextureAndroid?,
        ~accessibilityTraits?,
        ~accessibilityViewIsModal?,
        ~shouldRasterizeIOS?,
      ),
  );
  