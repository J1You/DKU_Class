class TV:
    def __init__(self,channel=11,volume=9,onoff=True):
        self.__channel =0
        self.__volume=volume
        self.__onoff=onoff
    def setChannel(self,channel):
        self.__channel=channel
    def getChannel(self):
        return self.__channel
    def setVolume(self,volume):
        self.__volume=volume
    def getVolume(self):
        return self.__volume
    def setOnOff(self,onoff):
        self.__onoff=onoff
    def view(self):
        print("channel = %s, volume = %s, onoff = %s"%(self.channel, self.volume, self.onoff))
        
