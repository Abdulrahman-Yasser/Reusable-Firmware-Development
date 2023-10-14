# Reusable-Firmware-Development
i will apply all the examples in Reusable-Firmware-Development on TIVA-C  (tm4c123gh6pm) bare-metal embedded


## rules for designing a reusable device driver 

- Separate Implementation from Configuration
- Create a simple low-level interface
- Provide error detection
- The StructOfRegister is the most reusable technique you can use
- with StructOfRegister you can collect all the bases for the module into one array, easier implementation
- Doxygen Documenting in header files is better than documenting the source files. because any developer will look to the header when he tries to use the module
- documenting functions in the header files to look like API implementation
- documenting important global variables in source files.
