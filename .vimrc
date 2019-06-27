" Automatic create header for Markdown
augroup subler
    autocmd BufNewFile **/subler.github.io/*.md
                \ source ~/.vim/custom/md_header.cfg |
                \ execute "4s/@CREATE_DATE@/".strftime("%Y-%m-%d %T")."/"
    autocmd BufWritePre,FileWritePre **/subler.github.io/*.md
                \ execute "normal ma" |
                \ execute "4s/最后更新.*/最后更新 ".strftime("%Y-%m-%d %T")."/"
    autocmd BufWritePost,FileWritePost **/subler.github.io/*.md execute "normal `a zz"
augroup END
