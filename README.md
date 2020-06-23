
Usando o sublime como editor de texto e o Livro " A Systematic Approach to Learning Robot Program" como guia.



Usando o EasyClangComplete e coloquei o autocomplete do ros com essas linhas de código a mais:

"-I/opt/ros/noetic/include",
"-I/opt/ros/noetic/include/roscpp",
"-I/usr/include/x86_64-linux-gnu/c++/9",

para formatação eu coloquei o SublimeASytlerFormater e troquei o atalho de ctrl+alt+f para ctrl+s para formatar toda vez que eu salvar.

Fonte:

https://packagecontrol.io/packages/EasyClangComplete

https://alliance.seas.upenn.edu/~cis700ii/dynamic/team4/2015/12/18/tutorial-how-to-configure-ros-ide-with-sublimec/

https://stackoverflow.com/questions/21345966/sublime-text-3-code-autoformatting



My bashrc file:

#Customized shortcuts

alias update='sudo apt-get update'
alias upgrade='sudo apt-get upgrade'
alias bashrc='gedit ~/.bashrc &'

#Ros related
source /opt/ros/noetic/setup.bash
source ~/ros_dev101/devel/setup.bash


Para fazer o catkin build funcionar foi preciso instalar:
pip3 install osrf-pycommon && sudo apt install python3-catkin-tools

https://docs.gitlab.com/ee/gitlab-basics/start-using-git.html


Tentando o novo edito VS Code