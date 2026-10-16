    case 0:
        pszText = "No errors.";
        break;
    case 1:
        pszText = "Tried to call lock a second time before unlock was called. ";
        break;
    case 2:
        pszText = "Tried to call a function on a data type that does not allow this type of functionality (ie calling Sound::lock on a streaming sound). ";
        break;
    case 3:
        pszText = "Neither NTSCSI nor ASPI could be initialised. ";
        break;
    case 4:
        pszText = "An error occurred while initialising the CDDA subsystem. ";
        break;
    case 5:
        pszText = "Couldn't find the specified device. ";
        break;
    case 6:
        pszText = "No audio tracks on the specified disc. ";
        break;
    case 7:
        pszText = "No CD/DVD devices were found. ";
        break;
    case 8:
        pszText = "No disc present in the specified drive. ";
        break;
    case 9:
        pszText = "A CDDA read error occurred. ";
        break;
    case 10:
        pszText = "Error trying to allocate a channel. ";
        break;
    case 11:
        pszText = "The specified channel has been reused to play another sound. ";
        break;
    case 12:
        pszText = "A Win32 COM related error occured. COM failed to initialize or a QueryInterface failed meaning a Windows codec or driver was not installed properly. ";
        break;
    case 13:
        pszText = "DMA Failure.  See debug output for more information. ";
        break;
    case 14:
        pszText = "DSP connection error.  Connection possibly caused a cyclic dependancy.  Or tried to connect a tree too many units deep (more than 128). ";
        break;
    case 15:
        pszText = "DSP Format error.  A DSP unit may have attempted to connect to this network with the wrong format. ";
        break;
    case 16:
        pszText = "DSP connection error.  Couldn't find the DSP unit specified. ";
        break;
    case 17:
        pszText = "DSP error.  Cannot perform this operation while the network is in the middle of running.  This will most likely happen if a connection or disconnection is attempted in a DSP callback. ";
        break;
    case 18:
        pszText = "DSP connection error.  The unit being connected to or disconnected should only have 1 input or output. ";
        break;
    case 19:
        pszText = "Error loading file. ";
        break;
    case 20:
        pszText = "Couldn't perform seek operation.  This is a limitation of the medium (ie netstreams) or the file format. ";
        break;
    case 21:
        pszText = "Media was ejected while reading. ";
        break;
    case 22:
        pszText = "End of file unexpectedly reached while trying to read essential data (truncated data?). ";
        break;
    case 23:
        pszText = "File not found. ";
        break;
    case 24:
        pszText = "Unwanted file access occured. ";
        break;
    case 25:
        pszText = "Unsupported file or audio format. ";
        break;
    case 26:
        pszText = "A HTTP error occurred. This is a catch-all for HTTP errors not listed elsewhere. ";
        break;
    case 27:
        pszText = "The specified resource requires authentication or is forbidden. ";
        break;
    case 28:
        pszText = "Proxy authentication is required to access the specified resource. ";
        break;
    case 29:
        pszText = "A HTTP server error occurred. ";
        break;
    case 30:
        pszText = "The HTTP request timed out. ";
        break;
    case 31:
        pszText = "FMOD was not initialized correctly to support this function. ";
        break;
    case 32:
        pszText = "Cannot call this command after System::init. ";
        break;
    case 33:
        pszText = "An error occured that wasn't supposed to.  Contact support. ";
        break;
    case 34:
        pszText = "On Xbox 360, this memory address passed to FMOD must be physical, (ie allocated with XPhysicalAlloc.) ";
        break;
    case 35:
        pszText = "Value passed in was a NaN, Inf or denormalized float. ";
        break;
    case 36:
        pszText = "An invalid object handle was used. ";
        break;
    case 37:
        pszText = "An invalid parameter was passed to this function. ";
        break;
    case 38:
        pszText = "An invalid seek position was passed to this function. ";
        break;
    case 39:
        pszText = "An invalid speaker was passed to this function based on the current speaker mode. ";
        break;
    case 40:
        pszText = "The syncpoint did not come from this sound handle. ";
        break;
    case 41:
        pszText = "The vectors passed in are not unit length, or perpendicular. ";
        break;
    case 42:
        pszText = "Reached maximum audible playback count for this sound's soundgroup. ";
        break;
    case 43:
        pszText = "Not enough memory or resources. ";
        break;
    case 44:
        pszText = "Can't use FMOD_OPENMEMORY_POINT on non PCM source data, or non mp3/xma/adpcm data if FMOD_CREATECOMPRESSEDSAMPLE was used. ";
        break;
    case 45:
        pszText = "Not enough memory or resources on console sound ram. ";
        break;
    case 46:
        pszText = "Tried to call a command on a 3d sound when the command was meant for 2d sound. ";
        break;
    case 47:
        pszText = "Tried to call a command on a 2d sound when the command was meant for 3d sound. ";
        break;
    case 48:
        pszText = "Tried to use a feature that requires hardware support.  (ie trying to play a GCADPCM compressed sound in software on Wii). ";
        break;
    case 49:
        pszText = "Tried to use a feature that requires the software engine.  Software engine has either been turned off, or command was executed on a hardware channel which does not support this feature. ";
        break;
    case 50:
        pszText = "Couldn't connect to the specified host. ";
        break;
    case 51:
        pszText = "A socket error occurred.  This is a catch-all for socket-related errors not listed elsewhere. ";
        break;
    case 52:
        pszText = "The specified URL couldn't be resolved. ";
        break;
    case 53:
        pszText = "Operation on a non-blocking socket could not complete immediately. ";
        break;
    case 54:
        pszText = "Operation could not be performed because specified sound/DSP connection is not ready. ";
        break;
    case 55:
        pszText = "Error initializing output device, but more specifically, the output device is already in use and cannot be reused. ";
        break;
    case 56:
        pszText = "Error creating hardware sound buffer. ";
        break;
    case 57:
        pszText = "A call to a standard soundcard driver failed, which could possibly mean a bug in the driver or resources were missing or exhausted. ";
        break;
    case 58:
        pszText = "Error enumerating the available driver list. List may be inconsistent due to a recent device addition or removal. ";
        break;
    case 59:
        pszText = "Soundcard does not support the minimum features needed for this soundsystem (16bit stereo output). ";
        break;
    case 60:
        pszText = "Error initializing output device. ";
        break;
    case 61:
        pszText = "FMOD_HARDWARE was specified but the sound card does not have the resources necessary to play it. ";
        break;
    case 62:
        pszText = "Attempted to create a software sound but no software channels were specified in System::init. ";
        break;
    case 63:
        pszText = "Panning only works with mono or stereo sound sources. ";
        break;
    case 64:
        pszText = "An unspecified error has been returned from a 3rd party plugin. ";
        break;
    case 65:
        pszText = "The number of allowed instances of a plugin has been exceeded. ";
        break;
    case 66:
        pszText = "A requested output, dsp unit type or codec was not available. ";
        break;
    case 67:
        pszText = "A resource that the plugin requires cannot be found. (ie the DLS file for MIDI playback or other DLLs that it needs to load) ";
        break;
    case 68:
        pszText = "The specified sound is still in use by the event system, call EventSystem::unloadFSB before trying to release it. ";
        break;
    case 69:
        pszText = "The specified sound is still in use by the event system, wait for the event which is using it finish with it. ";
        break;
    case 70:
        pszText = "An error occured trying to initialize the recording device. ";
        break;
    case 71:
        pszText = "Specified instance in FMOD_REVERB_PROPERTIES couldn't be set. Most likely because it is an invalid instance number or the reverb doesnt exist. ";
        break;
    case 72:
        pszText = "This subsound is already being used by another sound, you cannot have more than one parent to a sound.  Null out the other parent's entry first. ";
        break;
    case 73:
        pszText = "Shared subsounds cannot be replaced or moved from their parent stream, such as when the parent stream is an FSB file. ";
        break;
    case 74:
        pszText = "The subsound's mode bits do not match with the parent sound's mode bits.  See documentation for function that it was called with. ";
        break;
    case 75:
        pszText = "The error occured because the sound referenced contains subsounds when it shouldn't have, or it doesn't contain subsounds when it should have.  The operation may also not be able to be performed on a parent sound, or a parent sound was played without setting up a sentence first. ";
        break;
    case 76:
        pszText = "The specified tag could not be found or there are no tags. ";
        break;
    case 77:
        pszText = "The sound created exceeds the allowable input channel count.  This can be increased using the maxinputchannels parameter in System::setSoftwareFormat. ";
        break;
    case 78:
        pszText = "Something in FMOD hasn't been implemented when it should be! contact support! ";
        break;
    case 79:
        pszText = "This command failed because System::init or System::setDriver was not called. ";
        break;
    case 80:
        pszText = "A command issued was not supported by this object.  Possibly a plugin without certain callbacks specified. ";
        break;
    case 81:
        pszText = "An error caused by System::update occured. ";
        break;
    case 82:
        pszText = "The version number of this file format is not supported. ";
        break;
    case 83:
        pszText = "An Event failed to be retrieved, most likely due to 'just fail' being specified as the max playbacks behavior. ";
        break;
    case 84:
        pszText = "Can't execute this command on an EVENT_INFOONLY event. ";
        break;
    case 85:
        pszText = "An error occured that wasn't supposed to.  See debug log for reason. ";
        break;
    case 86:
        pszText = "Event failed because 'Max streams' was hit when FMOD_EVENT_INIT_FAIL_ON_MAXSTREAMS was specified. ";
        break;
    case 87:
        pszText = "FSB mismatches the FEV it was compiled with, the stream/sample mode it was meant to be created with was different, or the FEV was built for a different platform. ";
        break;
    case 88:
        pszText = "A category with the same name already exists. ";
        break;
    case 89:
        pszText = "The requested event, event group, event category or event property could not be found. ";
        break;
    case 90:
        pszText = "Tried to call a function on a complex event that's only supported by simple events. ";
        break;
    case 91:
        pszText = "An event with the same GUID already exists. ";
        break;
    case 92:
        pszText = "The specified project or bank has already been loaded. Having multiple copies of the same project loaded simultaneously is forbidden. ";
        break;
    case 93:
        pszText = "Music system is not initialized probably because no music data is loaded. ";
        break;
    case 94:
        pszText = "The requested music entity could not be found. ";
        break;
    case 95:
        pszText = "The music callback is required, but it has not been set. ";
        break;
    default:
        pszText = "Unknown error.";
