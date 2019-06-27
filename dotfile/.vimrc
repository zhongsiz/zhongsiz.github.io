"==========================================================================================
" Part 0: Plugins
"==========================================================================================
" Behave more useful as VIM, not Vi-compatible
set nocompatible

" vim-plug settings
call plug#begin('~/.vim/bundle')
" Plugin bundles list
" A tree explorer plugin for vim.
Plug 'scrooloose/nerdtree'
" A plugin of NERDTree showing git status
Plug 'Xuyuanp/nerdtree-git-plugin'
" A Git wrapper so awesome, it should be illegal
Plug 'tpope/vim-fugitive'
" quoting/parenthesizing made simple
Plug 'tpope/vim-surround'
" Insert or delete brackets, parens, quotes in pair
Plug 'jiangmiao/auto-pairs'
" A code-completion engine for Vim
Plug 'Valloric/YouCompleteMe'
" Generates config files for YouCompleteMe
Plug 'rdnetto/YCM-Generator', { 'branch': 'stable' }
" Help editing xml (and [x]html, sgml, xslt) files
Plug 'othree/xml.vim'
" A class outline viewer for Vim
Plug 'majutsushi/tagbar'
" Text filtering and alignment
Plug 'godlygeek/tabular'
" Improved C++11/14 STL syntax highlighting
Plug 'Mizuchi/STL-Syntax'
" Switch between header file and source file
Plug 'vim-scripts/a.vim'
" A much simpler way to use some motions in vim
Plug 'easymotion/vim-easymotion'
" Highlights trailing whitespace in red and provides :FixWhitespace to fix it.
Plug 'bronson/vim-trailing-whitespace'
" A command-line fuzzy finder written in Go
Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all' }
" Vim fzf plugin
Plug 'junegunn/fzf.vim'
" Vim plugin for the Perl module / CLI script 'ack'
Plug 'mileszs/ack.vim'
" Asynchronous Lint Engine
Plug 'w0rp/ale'
" A nicer Python indentation style for vim
Plug 'hynek/vim-python-pep8-indent'
" Provide easy code formatting in Vim by integrating existing code formatters.
Plug 'Chiel92/vim-autoformat'
" A Vim plugin that manages your tag files
Plug 'ludovicchabant/vim-gutentags'
" Simplify Doxygen documentation in C, C++, Python
Plug 'vim-scripts/DoxygenToolkit.vim'
call plug#end()


"==========================================================================================
" Part 1: Basic Settings
"==========================================================================================
" 启动工程特定的.vimrc文件
set exrc
set secure

" Set term suitable for Tmux
set term=screen-256color

" Enable automatic detect file type
filetype plugin indent on
" Enable syntax highlighting
syntax enable

" Set colorscheme
colorscheme desert

"file format
set fileformat=unix

" Copy indentation from current line when starting a new line
set autoindent
" Fold according to the indentation
set foldmethod=indent
" Deepest fold is 10 levels
set foldnestmax=10
" Don't fold by default
set nofoldenable

" Number of spaces that a <Tab> in the file counts for
let tabspace = 4
let &tabstop=tabspace
" Number of spaces when inserting a <Tab>
let &softtabstop=tabspace
" Each step of (auto)indentation
let &shiftwidth=tabspace
" Convert tabs to spaces
set expandtab

" Show current input command
set showcmd
" Show vim mode
set showmode
" Always show statusline
set laststatus=2
set statusline=\ %f%m%r%h%w\ %=%({%{&ff}\|%{(&fenc==\"\"?&enc:&fenc).((exists(\"+bomb\")\ &&\ &bomb)?\",B\":\"\")}%k\|%Y}%)\ %([%l,%v][%p%%]\ %)

" Show line number and set line number color
set number
hi LineNr ctermfg=DarkGrey ctermbg=Black

" Highlight searching while input
set incsearch
" Highlight searching result
set hlsearch
" Cancle hightlighting
nnoremap <F3> :set hlsearch!<CR>

" Hightlight the screen line of the cursor and set color
set cursorline
hi CursorLine cterm=bold ctermbg=DarkGrey ctermfg=White

" 中文乱码
set fileencodings=ucs-bom,utf-8,utf-16,gbk,big5,gb18030,latin1

" Set comments color
hi Comment ctermfg=DarkGray
" Set fold color
hi Folded ctermbg=DarkBlue ctermfg=White
" Set function color
hi Function ctermfg=DarkBlue
" Set visual mode color
hi Visual term=bold ctermbg=Black ctermfg=DarkGrey

" Some key mappings
" Move between split window use '<Ctrl> + hjkl'
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l
nnoremap <C-w>m <C-w>_ <C-w>\|

" Set block cursor
let &t_ti.="\e[1 q"
let &t_SI.="\e[5 q"
let &t_EI.="\e[1 q"
let &t_te.="\e[0 q"

" tags
set tags=./.tags;,.tags


"==========================================================================================
" Part 2: Plugin Settings
"==========================================================================================
" NERDTree Settings
" Open and toggle key mapping
map <C-t> :NERDTreeToggle<CR>

" nerdtree-git-plugin
let g:NERDTreeIndicatorMapCustom = {
      \ "Modified"  : "✹",
      \ "Staged"    : "✚",
      \ "Untracked" : "✭",
      \ "Renamed"   : "➜",
      \ "Unmerged"  : "═",
      \ "Deleted"   : "✖",
      \ "Dirty"     : "✗",
      \ "Clean"     : "✔︎",
      \ 'Ignored'   : '☒',
      \ "Unknown"   : "?"
      \ }

" YouCompleteMe Settings
" Default config file if no .ycm_extra_conf.py is found
let g:ycm_global_ycm_extra_conf = "~/.ycm_extra_conf.py"
" Always load .ycm_extra_conf.py when found
let g:ycm_confirm_extra_conf = 0
" Show the completion menu when typing inside comments.
let g:ycm_complete_in_comments = 1
" Warning and Error symbol, default '>>'
let g:ycm_error_symbol = 'e>'
let g:ycm_warning_symbol = 'w>'
" auto-close the 'preview' window after the user accepts the offered completion string
let g:ycm_autoclose_preview_window_after_completion = 1
" Goto declaration
nnoremap <leader>gl :YcmCompleter GoToDeclaration<CR>
" Goto definition
nnoremap <leader>gd :YcmCompleter GoToDefinition<CR>
" Goto definition/declaration
nnoremap <leader>gg :YcmCompleter GoTo<CR>
" Syntax keyword autocompletion
let g:ycm_seed_identifiers_with_syntax=1
" set completeopt=longest,menu

" Taglist
" Open and toggle key mapping
nmap <F4> :TagbarToggle<CR>

" Autoformat
" format upon saving your file
" au BufWrite * :Autoformat
" disable autoindent for filetypes that have incompetent indent files
" autocmd FileType markdown,tex,vim,tcl,cmake let b:autoformat_autoindent=0

" ALE
let g:ale_linters_explicit = 1
let g:ale_completion_delay = 500
let g:ale_echo_delay = 20
let g:ale_lint_delay = 500
let g:ale_echo_msg_format = '[%linter%] %code: %%s'
let g:ale_lint_on_text_changed = 'normal'
let g:ale_lint_on_insert_leave = 1
let g:airline#extensions#ale#enabled = 1

let g:ale_c_gcc_options = '-Wall -O2 -std=c99'
let g:ale_cpp_gcc_options = '-Wall -O2 -std=c++1z'
let g:ale_c_cppcheck_options = ''
let g:ale_cpp_cppcheck_options = ''

" Ack.vim
if executable('ag')
  let g:ackprg = 'ag --vimgrep'
endif

" vim-gutentags
" gutentags 搜索工程目录的标志，碰到这些文件/目录名就停止向上一级目录递归
let g:gutentags_project_root = ['.root', '.svn', '.git', '.hg', '.project']
" 所生成的数据文件的名称
let g:gutentags_ctags_tagfile = '.tags'
" 将自动生成的 tags 文件全部放入 ~/.cache/tags 目录中，避免污染工程目录
let s:vim_tags = expand('~/.cache/tags')
let g:gutentags_cache_dir = s:vim_tags
" 配置 ctags 的参数
let g:gutentags_ctags_extra_args = ['--fields=+niazS', '--extra=+q']
let g:gutentags_ctags_extra_args += ['--c++-kinds=+px']
let g:gutentags_ctags_extra_args += ['--c-kinds=+px']
"检测 ~/.cache/tags 不存在就新建
if !isdirectory(s:vim_tags)
  silent! call mkdir(s:vim_tags, 'p')
endif

" fzf.vim
nnoremap <silent> <Leader>f :Files<CR>
nnoremap <silent> <Leader>b :Buffers<CR>
nnoremap <silent> <Leader>a :Ag <C-R><C-W><CR>
nnoremap <silent> <Leader>A :Ack!<CR>


"==========================================================================================
" Part 3: Automatic Settings
"==========================================================================================
" Set syntax for a given filetype
" .exp(expect script), .mf(modulefiles) to tcl
autocmd BufNewFile,BufReadPost *.exp,*.mf set filetype=tcl "
" .md to markdown(overridde filetype of modula2)
autocmd BufNewFile,BufReadPost *.md set filetype=markdown
" map :q to q in help window
autocmd FileType help noremap <buffer> q :q<cr>

