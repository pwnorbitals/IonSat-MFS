# Specs OBC FSW :

## Specs for  flight software library :

- Features
    - clock synchronization 
    - on-orbit patching
    - EDF scheduling, opt-in
- Constraints
    - environnement
        - real time
    - safety & reliability
        - testing
            - hardware in the loop
            - emulated 
        - radiation mitigation
        - follows design guide
    - human ressources
        - built in C++
        - reusability
            - portability
            - code simplicity and modularity
        - documentation
            - tutorials
            - how-tos
            - reference
            - design
        - versionning
        - code style
    - storage
    - AIT = montage, intégration
    
## Specs for mission software

- Features
    - OBHD -> message handling, security, memory management
    - algos SCO -> propagation(!!), contrôle
    - algos SCA -> contrôle, detumbling, Bdot, ...
    - algos TM/TC -> protocoles
    - contrôle EPS -> safety
    - DO-178C / MISRA-C++ ?! No, but our own guidelines
- Constraints
    - Environment
        - Uses flight software library
        - end of life
        - maximum inactive period
    - budgets
        - data rate
        - memory
        - compute
        - ...
    - safety & reliability
        - follows design guide
    - human ressources
        - built in C++
        - versionning
        - code style