
import json
import subprocess
import sys
from pathlib import Path


def main():

    if len(sys.argv) != 3:
        print("Uso: py evaluar.py archivo.json ejecutable")
        return 2

    archivo = Path(sys.argv[1])
    ejecutable = str(Path(sys.argv[2]).resolve())

    try:
        casos = json.loads(
            archivo.read_text(encoding="utf-8")
        )
    except (OSError, json.JSONDecodeError) as error:
        print("Error al leer las pruebas:", error)
        return 2

    correctos = 0

    for caso in casos:

        try:
            resultado = subprocess.run(
                [ejecutable],
                input=caso["entrada"],
                text=True,
                capture_output=True,
                timeout=2
            )

            pasa = (
                resultado.returncode == 0
                and resultado.stdout.split()
                == caso["salida"].split()
            )

        except (subprocess.TimeoutExpired, OSError, KeyError):
            pasa = False
            resultado = None

        if pasa:
            correctos += 1
            print("Grupo", caso["grupo"], "OK")
        else:
            print("Grupo", caso["grupo"], "FALLO")

            if resultado is not None:
                print("Esperado:")
                print(caso["salida"])
                print("Obtenido:")
                print(resultado.stdout)

    print("Casos correctos:", correctos, "/", len(casos))

    return 0 if correctos == len(casos) else 1


if __name__ == "__main__":
    sys.exit(main())
