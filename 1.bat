@echo off
:loop
:: 生 成 测 试 数 据
data.exe > input.txt

:: 运 行 标 准 程 序
std.exe < input.txt > std_output.txt

:: 运 行 待 测 试 程 序
1271C.exe < input.txt > my_output.txt

比 较 输 出 结 果
fc std_output.txt my_output.txt > nul
if errorlevel 1 (
echo 发现错误！
echo 输入数据：
type input.txt
echo 标准输出：
type std_output.txt
echo 我的输出：
type my_output.txt
pause
exit
)
echo 测试通过
goto loop
