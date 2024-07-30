
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
- Start point and initial energy level of the spacecraft
- Map matrix with encoded values representing different space phenomenon

**spaceobject:** cells containing the number3 forming a 2-by-2 square represent
 large spaceo bjects.

**wormhole:** coupled cells containing the number 4 represent wormholes.

**home:** The cell containing the number 5 is the destination of the space craft
 (akahome).

**spacecurrent:** Consecutive cells containing the number 1 at both ends and the
 number 2 in the middle represent space currents.

Example:

```
7 6
5 0 1000
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

## Scenarios

1. **Infinite energy_no time constraint:** (implemented) The spacecraft must arrive at its
   destination without further challenges.
2. **Finite energy_no time constraint:** (implemented) The spacecraft must arrive at its
   destination before it runs out of its limited supply of energy.
3. **Finiteenergy_timeconstraint:** (not implemented!) The space craft must arrive at its destination
   before it runs out of its limited supply of energy in the shortest amount
   time possible

## Class Diagram

![UML-diagram](https://github.com/user-attachments/assets/7e9f76d0-68fc-4c7a-97a1-3262c3cf46f0)
