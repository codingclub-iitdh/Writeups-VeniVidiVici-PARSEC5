# Sign Of Life

### Challenge Description

A satellite, located light-years away from our Solar System, has transmitted a mysterious audio message back to Earth. However, the format is unlike anything we've encountered before. The sound is unsettling, almost otherworldly—could it be a form of alien communication?

### Listening to the wav file

The file seems to contain loud beeps with different intervals, like morse code. Plugging it into morse decoder from audio (You can find online tools for this), we can see there is in fact some text there. It says `DECOY TRY HARDER`.

### Spectrograph analysis

The sound still seems way too suspicious, maybe we can try spectrograh and analyse it. To do this we are using `Sonic Visualizer`. Import the audio into the project, then add a spectrograph layer by Layer -> Add Spectrogram -> All Channels. This will show you the visualized spectrogram which contains the plaintext flag.

Flag: `parsec{morphingaudio_1470347954}`
