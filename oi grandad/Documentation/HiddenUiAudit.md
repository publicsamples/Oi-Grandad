# Hidden UI Audit

Audit date: August 6, 2026

Source files:
- `/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/XmlPresetBackups/oi grandadUIData/oi grandadDesktop.xml`
- active scripts under `/Users/rick/Documents/GitHub/Oi-Grandad/oi grandad/Scripts`

Active-script scope for this audit:
- included: current root scripts and `ScriptProcessors/oigrandad`
- excluded: `ScriptProcessors/ui-up`, `ScriptProcessors/ogrep`, `ScriptProcessors/oigrandad-standalone`, `ScriptProcessors/AutoSave1`

Method:
- collect all desktop UI components with `visible="0"`
- compare their IDs against the active script set
- treat hidden controls with no script reference as orphaned for cleanup purposes

## Summary

- hidden controls in live desktop XML: `333`
- hidden controls with no active-script reference: `128`

These orphaned controls are the first candidates to remove from modulation destination registration.

## Orphaned Hidden Controls

### Random panels

- `RandMin32`, `RandMin33`, `RandMin34`
- `RandMax32`, `RandMax33`, `RandMax34`
- `RandLock32`, `RandLock33`, `RandLock34`
- `RandMin49`, `RandMin50`, `RandMin51`
- `RandMax49`, `RandMax50`, `RandMax51`
- `RandLock49`, `RandLock50`, `RandLock51`
- `RandMin66`, `RandMin67`, `RandMin68`
- `RandMax66`, `RandMax67`, `RandMax68`
- `RandLock66`, `RandLock67`, `RandLock68`

### Delay / time sync

- `DelayTimesync1`, `DelayTimesync2`, `DelayTimesync3`, `DelayTimesync4`
- `DelayTimesync6`, `DelayTimesync7`, `DelayTimesync8`, `DelayTimesync9`
- `DelayTimesync11`, `DelayTimesync12`, `DelayTimesync13`, `DelayTimesync14`
- `mastertime1`

### File / browser related

- `FileSelect1`, `FileSelect2`, `FileSelect3`, `FileSelect4`
- `FileSelect5`, `FileSelect6`, `FileSelect7`, `FileSelect8`
- `BoxSel`

### Voice / panel containers

- `V1`, `V2`, `V3`, `V4`, `V5`
- `settings`
- `Mod`
- `Panel1`
- `FloatingTile2`

### Crossfade / mode groups

- `XfModControls2`, `XfModControls3`, `XfModControls4`, `XfModControls5`
- `XfModControls6`, `XfModControls7`, `XfModControls8`
- `XfModControls10`, `XfModControls11`, `XfModControls12`, `XfModControls13`
- `XfMode5`, `XfMode6`, `XfMode7`, `XfMode8`
- `XfModeLabel5`, `XfModeLabel6`, `XfModeLabel7`, `XfModeLabel8`

### Position indicators

- `PosIndicator18`, `PosIndicator19`, `PosIndicator20`
- `PosIndicator22`, `PosIndicator23`, `PosIndicator24`
- `PosIndicator26`, `PosIndicator27`, `PosIndicator28`
- `PosIndicator30`, `PosIndicator31`, `PosIndicator32`

### Stage selectors

- `StgSel6`, `StgSel7`, `StgSel8`, `StgSel9`
- `Div3`

### Labels / images / placeholders

- `Label25`
- `Image12`
- `ScriptImage5`, `ScriptImage9`
- `ScriptLabel11`
- `ScriptLabel220`, `ScriptLabel221`, `ScriptLabel222`
- `ScriptLabel241`, `ScriptLabel242`, `ScriptLabel243`
- `ScriptLabel262`, `ScriptLabel263`, `ScriptLabel264`
- `ScriptLabel267`
- `ParamLabel2`, `ParamLabel3`, `ParamLabel6`
- `ParamLabel10`, `ParamLabel14`, `ParamLabel16`, `ParamLabel18`, `ParamLabel19`
- `ParamLabel50`, `ParamLabel53`, `ParamLabel77`, `ParamLabel83`
- `ParamLabel122`, `ParamLabel128`
- `ParamLabel167`, `ParamLabel173`
- `ParamLabel200`
- `blank1`, `blank2`

## Immediate cleanup recommendation

Before further matrix work:

1. exclude all orphaned hidden controls from matrix target registration
2. explicitly exclude all `RandMin*`, `RandMax*`, `RandLock*`
3. explicitly exclude all `MultPosA*`, `MultPosB*`, `MultPosC*`, `MultPosD*`
4. then review the destination list again before renaming modulators or macros
