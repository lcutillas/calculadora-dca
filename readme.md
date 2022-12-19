# Readme del proyecto Calculadora

## Alias locales añadidos:
- git st (git status)
- git b (git branch)

## Alias globales añadidos:
- git co (git checkout)
- git addall (git add .) - Añadir todos los ficheros con cambios al stage

## Uso de git bisect:
- Se ha introducido un error en el código y se ha realizado un commit.
- Se han hecho dos commits adicionales posteriormente.
- Entonces nos damos cuenta de que hay un error en el código, y decidimos usar git bisect para encontrarlo
- Ejecutamos 'git bisect start'
- Ejecutamos 'git bisect good HASH' eligiendo el commit inicial del repositorio, en el que sabemos que el código iba bien. HASH es por tanto el hash del commit inicial del proyecto.
- Ejecutamos 'git bisect bad HASH' siendo HASH el hash del último commit del proyecto, en el que sabemos que el código no funciona bien.
- Ahora git automáticamente se ha posicionado en un commit intermedio, siendo éste el commit en el que introdujimos el fallo. Compilamos y probamos el código, observando que el fallo existe. Indicamos a git que en este commit persiste el fallo con 'git bisect bad'.
- Ahora git se ha posicionado en el commit anterior al que introdujimos el fallo. Compilamos y probamos el código, observando que el funcionamiento es correcto. Indicamos a git que en este commit no está presente el fallo con 'git bisect good'.
- Dado que el error ha sido cercado, git nos indica ya cual es el primer commit que presentaba el error, siendo éste el que efectivamente nosotros sabíamos que habíamos introducido el fallo. Por lo tanto, hemos podido encontrar, gracias a git bisect, el commit en el que habíamos introducido el fallo. Git nos indica el hash de dicho commit, el autor, la fecha y hora, así como el mensaje con el que se realizó el commit.
- Ahora el repositorio está posicionado en el commit en el que se introdujo el fallo. Esto podemos saberlo ejectuando el comando 'git log', viendo que dicho commit está marcado como HEAD.
- Ejecutamos 'git bisect reset' para volver al commit en el que estábamos antes de iniciar la búsqueda con bisect.

## Hooks de git:
- Hemos creado un hook que comprueba que los mensajes de commit tienen al menos 3 palabras. Lo hemos realizado mediante un script de python. Hemos introducido el script en la carpeta 'hooks' que se encuentra dentro de la carpeta '.git' del proyecto. Además, le hemos otorgado permisos de ejecución con chmod. Comprobamos que funciona correctamente intentando hacer un commit con un mensaje corto, de forma que obtenemos el error. Cambiamos el mensaje por uno más largo y el commit se realiza correctamente.

