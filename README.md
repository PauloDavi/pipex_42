<h1 align="center">
	Pipex 
	 <img src="https://i.giphy.com/media/6qFTJz4fDRkdy/200.webp" width="35" alt="grade" />
</h1>

<p align="center">
  <img src="https://i.imgur.com/U7aswVo.png" width="140" alt="grade" />
  <img src="https://i.imgur.com/Ua8WU1K.png" width="120" alt="m" />
</p>

---

<p align="center">
	<b><i>Your Ultimate Shell Pipe Simulator</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/PauloDavi/pipex_42?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/PauloDavi/pipex_42?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/PauloDavi/pipex_42?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/PauloDavi/pipex_42?color=green" />
</p>

<h3 align="center">
	<a href="#-about-the-project">About</a>
	<span> • </span>
	<a href="#%EF%B8%8F-compile">Compile</a>
	<span> • </span>
	<a href="#-usage">Usage</a>
</h3>

---

## 💡 About the project
Pipex is your go-to solution for mastering the art of shell pipes in your command-line projects. This powerful utility enables you to seamlessly connect input and output files to your command sequences, just like you would in a Unix shell. But we didn't stop there; we've gone the extra mile!

With Pipex, not only can you efficiently pipe data between commands, but you can also take advantage of the bonus feature that allows you to execute an arbitrary number of commands sequentially. We've got you covered for those complex data processing tasks!

But wait, there's more! Pipex also handles the usage of here_doc, making it a versatile and essential tool for your command-line toolkit. Say goodbye to manual input and hello to a more efficient, automated pipeline experience with Pipex. Dive into the world of seamless data flow and command execution – try Pipex today!

## 🛠️ Compile

> The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

**Using it in your code**

You just need compile code with make:

```shell
make bonus
```

## 📋 Usage

The basic usability is like:

```bash
./pipex input_file cmd1 ... cmdN out_file
```

HERE_DOC usability is like:

```bash
./pipex here_doc DELIMITER cmd1 ... cmdN out_file
```

Where `DELIMITER` is a string than will delimiter end of `here_doc`
