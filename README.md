# World Clock

This is a very simple application to show time in different timezones.

![World Clock](/images/worldclock.png?raw=true)

## Config

The zones displayed can be configured in config file located in default config location for you OS, in linux that should be:
```
/home/user/.config/WorldClock/worldclock.conf
```

The config file is a simple `ini` file listing all the zones you want to display, for example:
```
[General]
zones="America/New_York,Europe/Berlin,Asia/Tokyo"
```

Config path can also be found in `About` window within application.

## Building

To build simply clone, open in `QtCreator` and build.
