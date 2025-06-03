---
layout: note
title: Tmux
---

# Tmux
1. Session
    * Create
        * `tmux new-session -s "sessionname"`
        * **Prefix** + `:new -s name`
    * **Prefix $**: Rename current session.
    * **Prefix s**: Switch sessions.
    * **Prefix d**: Detach sessions.
    * Kill a session: `tmux kill-session -t sessionname`
    * Attach to a session: `tmux a -t sessionname`
2. Windows
    * **Prefix ,**: Rename windows.
    * **Prefix c**: Create new windows.
    * **Prefix w**: List(Switch) windows.
        * **Prefix winid**: Switch windows.
    * **Prefix &**: Close current windows.
    * Redraw windows from different resolution minitor
        * Detach except self
            1. Attach to a session(optional): `tmux a #` or `tmux -a -t sessionname`
            2. Detach all other session: `tmux detach -a`
        * Detach the same session on different monitor
            1. **Prefix D** choose which monitor to detach.
3. Pane
    * Horizontally split: **Prefix \"**
    * Vertically split: **Prefix %**
    * Maximum pane: **Prefix z**
    * Close current pane: **Prefix x**
    * Switch to another pane: **Prefix o**
    * Switch pane with number:
        * **Prefix q** show pane number
        * Select pane number
    * Resize pane: **Prefix Up/Down**
    * Move panes:
        * To previous position: **Prefix {**
        * To next position **Prefix }**
    * Kill current pane: **Prefix x**
4. Others
    * Show shortcuts: **Prefix ?**
5. Copy mode
    * Setting
        * Enable vi-like movement: `set-windows-option -g mode-keys vi`
    * Copy
        * Enter copy mode: **Prefix [**
        * Select and copy: vi key-`v/y...`
        * Paste: **Prefix ]**
    * Buffer
        * List all buffers
            * `tmux list-buffers`
            * **Prefix #**
        * Show one buffer
            * `tmux show-buffer -b n`
        * Save buffer
            * `tmux save-buffer -b n foo.txt`

* *Refer*
    1. [Tmux - Linux从业者必备利器](http://cenalulu.github.io/linux/tmux/)
    2. [screen and tmux](http://www.dayid.org/os/notes/tm.html)
