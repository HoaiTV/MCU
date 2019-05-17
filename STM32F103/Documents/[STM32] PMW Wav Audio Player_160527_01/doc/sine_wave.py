# create a synthetic 'sine wave' wave file with
# set frequency and length
# tested with Python 2.5.4 and Python 3.1.1 by vegaseat

import math
import wave
import struct

def make_soundfile(freq=440, data_size=10000, fname="test.wav"):
    """
    create a synthetic 'sine wave' wave file with frequency freq
    file fname has a length of about data_size * 2
    """
    frate = 11025.0  # framerate as a float
    amp = 8000.0     # multiplier for amplitude

    # make a sine list ...
    sine_list = []
    for x in range(data_size):
        sine_list.append(math.sin(2*math.pi*freq*(x/frate)))

    # get ready for the wave file to be saved ...
    wav_file = wave.open(fname, "w")
    # give required parameters
    nchannels = 1
    sampwidth = 2
    framerate = int(frate)
    nframes = data_size
    comptype = "NONE"
    compname = "not compressed"
    # set all the parameters at once
    wav_file.setparams((nchannels, sampwidth, framerate, nframes,
        comptype, compname))
    # now write out the file ...
    print( "may take a moment ..." )
    for s in sine_list:
        # write the audio frames to file
        wav_file.writeframes(struct.pack('h', int(s*amp/2)))
    wav_file.close()
    print( "%s written" % fname )


# set some variables ...
freq = 1000.0#440.0
# data size, file size will be about 2 times that
# duration is about 4 seconds for a data_size of 40000
data_size = 40000

# write the synthetic wave file to ...
fname = "WaveTest2.wav"

make_soundfile(freq, data_size, fname)
