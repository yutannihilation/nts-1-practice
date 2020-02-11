# nts-1-practice
An attempt to create a simple ocsilator with Korg NTS-1

## Preparation

Clone this repo as `/path/to/logue-sdk/platform/nutekt-digital/build` (since `build` is ignored).

## Add an example

1. Copy `000_template` and name the folder
2. Edit `project.mk` and `manifest.json`

## Resources

### References

* https://github.com/korginc/logue-sdk/tree/master/platform/nutekt-digital#creating-a-new-project
* [Definition of `user_osc_param_t`](https://github.com/korginc/logue-sdk/blob/8c261c547815e892c57824b26631863b2002635c/platform/nutekt-digital/inc/userosc.h#L60-L70)

### Examples

* [`tasks.json` for VS Code](https://github.com/kinoshita-lab/nts-1_simple_examples/blob/master/000_nop/.vscode/tasks.json)
* https://github.com/centrevillage/cv_logue/blob/master/osc/wt_test/wt_test.cpp
