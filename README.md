# C-Style-Format

Example:

```C++
const std::string format = "The integer value: %d, the string value: %s";

/* static format example */
const std::string static_message = StringFormatStatic<128>(format, 10, "Static example");
std::cout << static_message << std::endl;

/* dynamic format example */
const std::string dynamic_message = StringFormatDynamic(format, 15, "Dynamic example");
std::cout << dynamic_message << std::endl;
```

Output:

```
The integer value: 10, the string value: Static example
The integer value: 15, the string value: Dynamic example
```
