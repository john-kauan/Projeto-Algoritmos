## 🚀 Como Executar o Projeto

Para rodar este projeto em C, siga os passos abaixo.

---

### ✅ Pré-requisitos

Antes de começar, você precisa ter instalado:

- **GCC ou Clang** (compilador C)
- **CMake** (para configurar o projeto)
- **Make**
- (Opcional) **CLion**, caso queira rodar pela IDE

---

## ▶️ Executando pelo CLion (Recomendado)

1. Abra o **CLion**.
2. Clique em **Open** e selecione a pasta do projeto.
3. Aguarde o **CMake** configurar automaticamente.
4. Clique no botão **Run** (setinha verde no canto superior direito).
5. O programa será compilado e executado.

---

## ▶️ Executando pelo Terminal (Linux / WSL / Mac)

Dentro da pasta do projeto, execute:

```bash
mkdir build
cd build
cmake ..
make
./projeto
