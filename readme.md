# A custom keymap with a number row

![Planck with number row](https://raw.githubusercontent.com/BeHive/PlanckLayout/master/IMG_9879.jpg)


### The keymap defaults to mac

``` lower+raise+w ``` activates Windows mode, while ``` lower+raise+w ``` goes back to mac mode

These two modes are needed because of the different key combinations that both OSes use for the functionalities programmed into the rotary encoder

If you want to change the default mode from mac to win, just change ```bool mac_mode = true;``` to ```bool mac_mode = false;``` in keymap.c


### Ctrl Alt and OS Key

```alt``` ```ctrl``` and ```os key``` are programmed with tap-keys as there was no place left on the keyboard to host dedicated keys for them. As such, some keys are configured to have different behaviours if they are tapped or held.

```alt``` is mapped to ```hold 1```

```ctrl``` is mapped to ```hold 2```

```os key``` is mapped to ```hold 3```

### Auto Shift

```AUTO_SHIFT_ENABLE``` is set to on, meaning that any key held for 1.75 seconds will produce it's shifted symbol

There are 3 exceptions to this behaviour, and those are ```1``` ```2``` ```3```, because of the mappings described in the previous point

### Rotary Encoder

The rotary encoder has the following mapping:

- normal: scroll up and down. Click toggles music mode
- raise: find next and find previous. The click action will copy the selected text and find it
- lower: undo and redo. Click toggles muse mode
- lower+raise: volume up and down, with mute/unmute on click

### Default Layout

The default layout is as follows:

|  ```MUSIC``` | ```1``` | ```2``` | ```3``` | ```4``` | ```5``` | ```6``` | ```7``` | ```8``` | ```9``` | ```0``` | ```Space``` |
|:-----:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-----:|
|  ```Tab```  | ```Q``` | ```W``` | ```E``` | ```R``` | ```T``` | ```Y``` | ```U``` | ```I``` | ```O``` | ```P``` |  ```Bksp``` |
|  ```Esc```  | ```A``` | ```S``` | ```D``` | ```F``` | ```G``` | ```H``` | ```J``` | ```K``` | ```L``` | ```;``` |   ```'```   |
| ```Shift``` | ```Z``` | ```X``` | ```C``` | ```V``` |```B``` |``` N``` | ```M``` | ```,``` | ```.``` | ```/``` | ```Enter``` |

For the layout of each additional layer, please refer to the ```keymap.c``` file