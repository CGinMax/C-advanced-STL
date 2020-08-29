
let mapleader=";"
set nocompatible
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
"set rtp+=~/.vim/plugin/clang_complete.vim

"vundle管理的插件列表必须位于vundle#begin()和vundle#end()之间
call vundle#begin()
 
"避免PluginClean把自己卸载了
Plugin 'VundleVim/Vundle.vim'
Plugin 'mzlogin/vim-markdown-toc'
Plugin 'octol/vim-cpp-enhanced-highlight'
Plugin 'derekwyatt/vim-fswitch'
Plugin 'majutsushi/tagbar'
Plugin 'preservim/nerdcommenter'
Plugin 'fatih/vim-go'
Plugin 'vhdirk/vim-cmake'
Plugin 'Valloric/YouCompleteMe'
Plugin 'preservim/nerdtree'
Plugin 'Raimondi/delimitMate'
"添加clang插件
"Plugin 'rip-rip/clang_complete'
 

"========clang设置===============
"let g:clang_complete_copen=1
"let g:clang_periodic_quickfix=1
"let g:clang_snippets=1
"let g:clang_user_options='-std=c99 -stdlib=libc++ -std=c++11 -IIncludePath'
"let g:clang_auto_select=1
"let g:clang_close_preview=1
"let g:clang_complete_macros=1
"let g:clang_use_library=1
"let g:clang_library_path="/usr/lib/llvm/"
"let g:neocomplcache_enable_at_startup=1
"
 
"插件列表结束
call vundle#end()
filetype plugin indent on
"安装插件，先找到其在github的地址，再将配置信息加入.vimrc中的call
"vundle#begin()和call vundle#end()之间，最后进入vim执行
":PluginInstall 便可自动安装
"要卸载插件，先在.vimrc中注释或删除对应插件配置信息，然后在vim中执行
":PluginClean便可卸载对应插件
"批量更新，只需执行:PluginUpdat


"=============================
filetype on
filetype plugin on

"set encoding=utf-8	"使用utf-8编码
set helplang=cn	"设置为中文帮助文档，需下载并配置之后生效
set number
set showcmd
set showmatch
"set clipboard=unnamed,unnamedplus	"可以从vim复制到剪贴板中
set mouse=a		"可以在buffer的任何地方使用鼠标
set hlsearch		"显示高亮搜索
"set incsearch
set history=40		"默认指令记录是20
set ruler		"显示行号和列号
set wrap
syntax enable
syntax on
 
"===============文本格式排版====================
set tabstop=4		"设置Tab键的占位符
set shiftwidth=4	"设置自动对齐的缩进级别
set softtabstop=4   "连续4个空格转换成tab
set autoindent		"配合下面一条命令根据不同语言类型进行不同的缩进操作
set cindent		"以c语言风格自动缩进
filetype plugin indent on
"set smartindent	"自动识别以#开头的注释，不进行换行
"
set t_Co=256

"==============按键映射========================
"inoremap

"========fswitch文件跳转========
"*.cpp和.h之间切换
nmap <silent> <Leader>sw :FSHere<cr>

"========YouCompleteMe==========
let g:ycm_use_clangd=1
" YCM 补全菜单配色
" 菜单
highlight Pmenu ctermfg=231 ctermbg=235 guifg=grey100 guibg=grey15
" 选中项
highlight PmenuSel ctermfg=231 ctermbg=33 guifg=grey100 guibg=dodgerblue1
" 补全功能在注释中同样有效
let g:ycm_complete_in_comments=1
" 允许 vim 加载 .ycm_extra_conf.py 文件，不再提示
"let g:ycm_confirm_extra_conf=0
" 开启 YCM 标签补全引擎
let g:ycm_collect_identifiers_from_tags_files=1
" 引入 C++ 标准库tags
"set tags+=/data/misc/software/misc./vim/stdcpp.tags
" YCM 集成 OmniCppComplete 补全引擎，设置其快捷键
inoremap <leader>; <C-x><C-o>
" 补全内容不以分割子窗口形式出现，只显示补全列表
set completeopt-=preview
" 从第一个键入字符就开始罗列匹配项
let g:ycm_min_num_of_chars_for_completion=1
" 禁止缓存匹配项，每次都重新生成匹配项
let g:ycm_cache_omnifunc=0
" 语法关键字补全			
let g:ycm_seed_identifiers_with_syntax=1


"========clang_complete的clang路径============
"let g:clang_library_path='/usr/lib/llvm-3.9/lib/libclang.so.1'

"========c/c++语法高亮设置=======
"let g:cpp_class_scope_hightlight=1
"let g:cpp_member_variable_highlight=1
"let g:cpp_class_decl_highlight=1
"let g:cpp_experimental_template_highlight = 1
"let g:cpp_concepts_highlight = 1"

"==============ctags=============
:set tags+=/home/cjmax/Documents/tags
":set tags+=/home/cjmax/Documents/HighPerformanceNetWork/tags
" 正向遍历同名标签
nmap <Leader>tn :tnext<CR>
" 反向遍历同名标签
nmap <Leader>tp :tprevious<CR>

"===============tagbar=============
" 设置 tagbar 子窗口的位置出现在主编辑区的左边 
let tagbar_left=1 
" 设置显示／隐藏标签列表子窗口的快捷键。速记：identifier list by tag
"nnoremap <Leader>ilt :TagbarToggle<CR>
nmap <silent> <F9> :TagbarToggle<CR> 
" 设置标签子窗口的宽度 
let tagbar_width=32 
" tagbar 子窗口中不显示冗余帮助信息 
let g:tagbar_compact=1
" 设置 ctags 对哪些代码标识符生成标签
let g:tagbar_type_cpp = {
    \ 'kinds' : [
         \ 'c:classes:0:1',
         \ 'd:macros:0:1',
         \ 'e:enumerators:0:0', 
         \ 'f:functions:0:1',
         \ 'g:enumeration:0:1',
         \ 'l:local:0:1',
         \ 'm:members:0:1',
         \ 'n:namespaces:0:1',
         \ 'p:functions_prototypes:0:1',
         \ 's:structs:0:1',
         \ 't:typedefs:0:1',
         \ 'u:unions:0:1',
         \ 'v:global:0:1',
         \ 'x:external:0:1'
     \ ],
     \ 'sro'        : '::',
     \ 'kind2scope' : {
         \ 'g' : 'enum',
         \ 'n' : 'namespace',
         \ 'c' : 'class',
         \ 's' : 'struct',
         \ 'u' : 'union'
     \ },
     \ 'scope2kind' : {
         \ 'enum'      : 'g',
         \ 'namespace' : 'n',
         \ 'class'     : 'c',
         \ 'struct'    : 's',
         \ 'union'     : 'u'
     \ }
\ }

"===============其他===========================
"配置立即生效
autocmd BufWritePost $MYVIMRC source $MYVIMRC

"================nerdtree======================
" 使用 NERDTree 插件查看工程文件。设置快捷键，速记：file list
nmap <Leader>fl :NERDTreeToggle<CR>
" 设置NERDTree子窗口宽度
let NERDTreeWinSize=32
" 设置NERDTree子窗口位置
let NERDTreeWinPos="right"
" 显示隐藏文件
let NERDTreeShowHidden=1
" NERDTree 子窗口中不显示冗余帮助信息
let NERDTreeMinimalUI=1
" 删除文件时自动删除文件对应 buffer
let NERDTreeAutoDeleteBuffer=1
