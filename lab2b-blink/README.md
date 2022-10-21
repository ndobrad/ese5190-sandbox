University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2B

    Nikola Obradovic
    Link to setup guide: https://github.com/ndobrad/ese5190-tools/blob/main/setup/qtpy_rp2040_setup.md


# Lab 2B

### 5.2 Breadboard

![](img/blink.gif)

### 5.3 Proposal
My plan is to build a peripheral centered around the [AMT102v rotary encoder](https://www.mouser.ie/datasheet/2/670/amt10_v-1775837.pdf) (because I happen to have one on hand). Since the encoder has 3 outputs (2 pulse signals and an index signal), I would like to use an I2C GPIO expander to interface with encoder. This is pending availability in the lab, I did not have a chance to check if this is something they have in stock. Backup plan if the I2C component is not available is to just interface with 2 pulse signals, which will still let me measure relative rotation. Stretch goal is to use the [Pololu Tic T834](https://www.pololu.com/product/3132) (also on hand) over I2C to control the stepper motor that is epoxied to my encoder.