# ArqComp-RISCV-A2023

Camino de Datos RISC-V de 32 bits.

Este proyecto implementa un camino de datos RISC-V de 32 bits 
utilizando el lenguaje de descripción de hardware SystemC. 
El camino de datos es capaz de ejecutar un conjunto básico de 
instrucciones RISC-V y muestra el contenido de cada registro de 
instrucción en cada ciclo de reloj.

Requisitos

Para compilar y ejecutar el proyecto, necesitarás tener instalado:

SystemC (versión 2.3.3)

C++ Compiler (compatible con C++11).


Estructura del Proyecto.

El proyecto se compone de los siguientes archivos:

main.cpp: Punto de entrada del programa. Aquí se realiza la carga 
del archivo de programa y se inicia la ejecución del camino de datos.

alu.cpp, alu.h: Implementación del módulo ALU (Unidad Lógica-Aritmética).

control_unit.cpp, control_unit.h: Implementación del módulo Unidad de Control.

data_memory.cpp, data_memory.h: Implementación del módulo Memoria de Datos.

instruction_memory.cpp, instruction_memory.h: Implementación del módulo Memoria 
de Instrucciones.

registers.cpp, registers.h: Implementación del módulo Registro de Instrucción.

riscv_datapath.cpp, riscv_datapath.h: Implementación del camino de datos principal 
que conecta todos los módulos.

Además de estos módulos también tienen componentes adicionales como lo son Imm gen, 
los generadores de inmediatos; los multiplexores MUX; los bancos de pruebas, tesbench, etc,. 


Compilación y Ejecución

Asegúrate de tener instaladas las dependencias mencionadas en los Requisitos.

Descarga los archivos en tu máquina local.

Abre una terminal y navega hasta el directorio del proyecto.

Compila los archivos usando el siguiente comando: make

Una vez compilado, ejecutar el programa con el siguiente comando: ./test o make run


Contribuciones.

Eugenia Ramirez.
Maeva Puente.
Gregory Hernandez.
Jose Leonel Rivas.
