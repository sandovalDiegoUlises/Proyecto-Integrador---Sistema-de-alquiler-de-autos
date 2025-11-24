# Proyecto-Integrador-LSI-en-C---Sistema-de-alquiler-de-autos
<h1 align="center">🚗 RoSa Mobility – Sistema de Alquiler de Vehículos</h1>

<p align="center">
  <strong>Proyecto Integrador – Algoritmos y Estructuras de Datos II</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Lenguaje-C-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Estado-Terminado-yellow?style=for-the-badge" />

  
---

# 📘 Descripción del proyecto
RoSa Mobility es un **Sistema de Alquiler de Vehículos** desarrollado en lenguaje C.  
Permite gestionar de forma eficiente la disponibilidad de autos y camionetas, ofreciendo búsquedas por:

- Marca  
- Modelo  
- Color  
- Tipo de alquiler (día, semana o mes)

El sistema persiste los datos mediante **archivos binarios**, aplicando estructuras dinámicas, corte de control, y múltiples técnicas vistas en la materia.

---

# ✨ Características principales
✔ Gestión de flota (autos y camionetas)  
✔ Alquiler por día, semana o mes  
✔ Métodos de pago con descuentos e intereses  
✔ Actualización automática de estado en archivo binario  
✔ Búsqueda avanzada por marca, modelo y color  
✔ Reportes y estadísticas mediante corte de control  
✔ Ticket final del alquiler formateado profesionalmente  

---

# 🚀 Ejecución
1. Asegurarse de que todos los archivos del proyecto estén en la misma carpeta.  
2. Abrir **`menuAlquiler.c`** en su IDE favorito (recomendamos Dev C++ o  Code::blocks).  
3. Compilar ese archivo y ejecutar el programa.

---


### 📍 2. Menú principal

El usuario podrá seleccionar:

- **1)** Alquilar un vehículo  
- **2)** Buscar vehículo  
- **3)** Ver reportes y listados  
- **0)** Salir del programa  

---

### 🔄 3. Proceso de alquiler

Cuando se confirma el alquiler:

```c
aux.estado = 1;
fseek(archivoAutos, pos, SEEK_SET);
fwrite(&aux, sizeof(vehiculo), 1, archivoAutos);

```

---

## 🧮 Cálculo del costo del alquiler

4. El cálculo del costo depende del tipo de alquiler seleccionado por el usuario:

```c
total = dias * aux.PrecioDia;
// o
total = semanas * aux.PrecioSemana;
// o
total = meses * aux.PrecioMes;
```

---

## 💰 Métodos de pago y descuentos

5. Si el usuario realiza el pago en **efectivo**, el sistema aplica automáticamente un **descuento del 10%** sobre el precio final:

```c
total = total - (total * 0.10);
```

---

## 📊 Reportes y estadísticas (corte de control)

6. Para generar los reportes del sistema —cantidad de vehículos alquilados, disponibles, totales por marca y por tipo— se realiza un **corte de control**, leyendo el archivo completo registro por registro:

```c
while (fread(&aux, sizeof(vehiculo), 1, archivoAutos) == 1) {
    // acá se cuentan los autos alquilados o disponibles por tipo (auto o camioneta)
}
```

---

## 👥 Autores

- **Romero Fernández, Rubén Tiburcio**  
- **Romero, Matías Luciano**  
- **Romero, Franco Exequiel**  
- **Sandoval, Diego Ulises**
