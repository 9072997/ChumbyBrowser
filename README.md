webkitCP is a webkit based control pannel for the Chumby One. It is intended to be run off of a usb stick. For binary builds see the [thred](http://forum.chumby.com/viewtopic.php?id=8716) on the fourm.

## Basic Usage
On startup you will be asked to calibrate the touchscreen. You will only need to do this once. After calibration is done you will be presented with the control pannel. At the top their is a clock and beneth that their are three buttons. In order from right to left they are My Widgets, Add Widgets, and Settings represented by the Chumby logo, a plus, and a gear respectively. Below that is a red bar used for adjusting volume.The fisrt time you start the Control Pannel you will have no widgets, so tap the green plus. You will see a list of avalible widgets. Right now the selection is limited, sorry. Tap the yellow arrow next to the name of any application to install it (NOTE: widgets have total access to your Chumby, and theirfore your network; they could view network trafic and plant viruses, so exercise caution, as with the installation of any other program). After that you will see a screen asking for confirmation. Tap the green check to cointinue installation. After the widget is installed you will be returned to the main screen of the control pannel. To open the widget tap the Chumby logo, then tap the yellow arrow next to the widget you would like to view. That widget is now running to see it you must press the top button of the Chumby. The top button is used to switch between the widget view and the control pannel view.

## Settings
In settings you may click the red "X" to uninstall widgets. The red bar at the bottom adjusts brightness. The blue icon of two computers will activate sshd so you can ssh into the chumby (NOTE: no action is displayed on the screen when sshd is starded). The red arrow will take you back to the main screen of the control pannel.

## Widgets
For those who would like to write widgets here is the format: A widget is a tar file with the extention ".chw" (for CHumby Widget). The tar file may be gzip compressed and may cointain any combination of the folders "usr", "www", and "bin", the contents of which will be copied to "/mnt/webkitCP/userapp/usr", "/mnt/webkitCP/userapp/www", and "/mnt/webkitCP/userapp/bin" respectively. Note that the www folder in a ".chw" file may cointain multiple widgets, so a ".chw" file is more of a package. It is recomended that your package include a folder inside the www folder with the name of your widget. The list of installed widgets is obtained by listing all folders in "/mnt/webkitCP/userapp/www". When the user opens your widget that folder will be loaded in a fullscreen webkit frame. The "bin" folder may be used for custom scripts or binaries which will be accessible to javascript. Note that scripts (bash, perl, and php) may be used directly in the "www" folder as cgi scripts. The usr folder is intended for storing misalanious files like user prefrences. Remenber that it is shared, so put your files in a folder, or name your files didtinctively.

### Binaries
Custom binaries may reside in the bin folder of a ".chw" file. To use them use the javascript code
```javascript
result = ChumbyCommandHandler.run("myCommandName", []);
```
or
```javascript
result = ChumbyCommandHandler.run("myCommandName", ["argument1", "argument2", "argument3"]);
```
the object result will cointain the error code, stdout, and stderr from the program. These may be accessed like this
```javascript
console.log("Exit code:", result.exitcode);
console.log("stdout:",    result.stdout);
console.log("stderr:",    result.stderr);
````

### More Comming Soon

## Credit

Based on ChumbyBrowser by Stefan A. van der Meer (stefanvandermeer@gmail.com)

I am not affiliated with Chumby Industries in any way.
