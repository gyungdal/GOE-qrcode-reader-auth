# ETRI QRCode reader & auth
에트리 방문자 QR코드 인증기

## GPIO SET
- pin map

![PIN MAP](https://pihw.files.wordpress.com/2013/01/rev12gpio.png)

| Name | Pin |
|--------|--------|
| BUZZER   |   22  |
| RED LED   |   23  |
| GREEN LED   |   24  |
| BLUE LED   |   25  |


## Depended
1. PI Camera Enable
	```
	sudo raspi-config
    ```
	![camera enable](https://dab1nmslvvntp.cloudfront.net/wp-content/uploads/2015/07/1436675616rpicameraenable.png)
2. zbar-tools
	If you not install this tool, you should install [zbar-tools](http://packages.ubuntu.com/precise/graphics/zbar-tools).
    ```
    sudo apt-get install zbar-tools
    ```

## Caution
1. **Network Connect**
```
if you disconnect from internet, this code maybe doesn't work...
```