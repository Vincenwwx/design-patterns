# Command Pattern

## Introduction
> The Command Pattern encapsulates a request as an object, thereby letting you parameterize other objects with different requests, queue or log requests, and support undoable operations.  
-- _Head First Design Patterns_

## Scenario
- A customer wants to build a smart home by controlling EVERYTHING with just a control center. 

- The customer orders a control center with N customized options. Each option can be set to be simple operations like "turning on TV" or complex operations such as "making room comfortable".

- The customer purchases a TV, a light and an air conditioner. They all provide different controlling methods.

- Purchasing TV, light and air conditioner is just a start. More furnitures are on their way home.

<p align="center">
<img src="https://github.com/Vincenwwx/design-patterns/assets/49132368/dc25fbe3-e62f-4a66-a2cd-2122cbee82cd" width="80%"/>
</p>

## Solution
### Basic Idea
The most straightforward idea should be creating a `ControlCenter` class and different furnitures classes such as `Television`, `Light` and etc. And the control center should reference different furnitures such that it knows how to operate on them.

This design is bad for the following reasons:

- Everytime a new furniture is brought in, the control center needs to be updated to provide new commands on that. This violates the principle: 
> Class should be open for extension, but closed for modification.

- As time goes by, the control center class will become bloated as it references more funiture classes. And any changes made by the furniture manufacturers could enforce changes on the `ControlCenter` class, which violates another well-known design principle:
> A class should have one reason to change.

### Better Idea Using Command Pattern
<p align="center">
<img src="https://github.com/Vincenwwx/design-patterns/assets/49132368/45ab5cb5-4a10-4c16-aecd-b3b405c337b3" width="80%"/>
</p>

In this design:
- The soul is the `Command` (interface) class. It defines two pure functions: `execute()` for how the command should be done and `back()` to undo the command. 

- All operations on various furnitures are derived from this base interface. Each operation command will reference the corresponding furniture.

- The `ControlCenter` class only knows the `Command` class, and the more specific commands are passed to it using polymorphism.

Why good?
- Now most classes are fixed, i.e., not susceptible to changes.

If you are asking why, think about what changes need to be made if a new furniture air conditioner comes and the control center should add basic commands for that, such as "turn on/off air conditioner" (Hints can be found in [PR](https://github.com/Vincenwwx/design-patterns/pull/5#issuecomment-1912848322)). No changes have to be made to the existent classes.

## Homework

Implement a new furniture `AirConditioner` and two corresponding commands, namely `TurnOnAc()` and `TurnOffAcAfterOneHour()`, mentioned beforehand.