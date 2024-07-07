
# Space Craft Project

## Project Details

**Instructor**: Dr. Mir Hossein Dezfoulian  
**Course**: Design and Analysis of Algorithms - Spring 2024  
**Project by**: Navid P. Panahi 

## Overview

During the AR41-CEH space expedition, the Falcon II uncrewed spacecraft
 was sucked into an unknown wormhole due to a routing unit (RU) malfunction.
 Fortunately, Falcon II was able to escape the wormhole. Our headquarters has
 successfully opened a communication channel to the spacecraft. Unfortunately,
 the channel won’t last very long and connection may be lost at any moment.
 Falcon II responded to a status report request with the following:
 
overall: operational (partially damaged)
 
RU status: unreliable
 
energy level: low (exact value unknown)
 
location: unknown
...

 According to the message highlights, The RU of the spacecraft has been damaged
 and needs to be reprogrammed. As the head of the chief engineering team,
 you’ve been tasked to reprogram the RU of the Falcon II spacecraft remotely.
 The RU you reprogram must lead the spacecraft back home before it runs out of
 energy while avoiding collision with other space objects.

 




## Installation

1. Clone the repository:
    ```
    git clone https://github.com/acontius/Space-Craft.git
    ```
2. Navigate to the project directory:
    ```
    cd space-craft
    ```

## Usage

### Input Format

The input is provided as a text file containing:
- Size of the map matrix
- Initial energy level of the spacecraft
- Map matrix with encoded values representing different space phenomena

Example:
```
7
6
50
1000
004050
033000
033010
000220
002200
001040
000000
```

### Output Format

The output is the result of the logging system detailing each decision made by the spacecraft, the energy consumed, and the time taken.

## Class Diagram

//this will add after complete project.
