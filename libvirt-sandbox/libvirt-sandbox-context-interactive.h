/*
 * libvirt-sandbox-context-interactive.h: libvirt sandbox interactive context
 *
 * Copyright (C) 2011 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Author: Daniel P. Berrange <berrange@redhat.com>
 */

#if !defined(__LIBVIRT_SANDBOX_H__) && !defined(LIBVIRT_SANDBOX_BUILD)
#error "Only <libvirt-sandbox/libvirt-sandbox.h> can be included directly."
#endif

#ifndef __LIBVIRT_SANDBOX_CONTEXT_INTERACTIVE_H__
#define __LIBVIRT_SANDBOX_CONTEXT_INTERACTIVE_H__

G_BEGIN_DECLS

#define GVIR_SANDBOX_TYPE_CONTEXT_INTERACTIVE            (gvir_sandbox_context_interactive_get_type ())
#define GVIR_SANDBOX_CONTEXT_INTERACTIVE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GVIR_SANDBOX_TYPE_CONTEXT_INTERACTIVE, GVirSandboxContextInteractive))
#define GVIR_SANDBOX_CONTEXT_INTERACTIVE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GVIR_SANDBOX_TYPE_CONTEXT_INTERACTIVE, GVirSandboxContextInteractiveClass))
#define GVIR_SANDBOX_IS_CONTEXT_INTERACTIVE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GVIR_SANDBOX_TYPE_CONTEXT_INTERACTIVE))
#define GVIR_SANDBOX_IS_CONTEXT_INTERACTIVE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GVIR_SANDBOX_TYPE_CONTEXT_INTERACTIVE))
#define GVIR_SANDBOX_CONTEXT_INTERACTIVE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GVIR_SANDBOX_TYPE_CONTEXT_INTERACTIVE, GVirSandboxContextInteractiveClass))

typedef struct _GVirSandboxContextInteractive GVirSandboxContextInteractive;
typedef struct _GVirSandboxContextInteractivePrivate GVirSandboxContextInteractivePrivate;
typedef struct _GVirSandboxContextInteractiveClass GVirSandboxContextInteractiveClass;

struct _GVirSandboxContextInteractive
{
    GVirSandboxContext parent;

    GVirSandboxContextInteractivePrivate *priv;

    /* Do not add fields to this struct */
};

struct _GVirSandboxContextInteractiveClass
{
    GVirSandboxContextClass parent_class;

};

GType gvir_sandbox_context_interactive_get_type(void);

GVirSandboxContextInteractive *gvir_sandbox_context_interactive_new(GVirConnection *connection,
                                                                    GVirSandboxConfigInteractive *config);

GVirSandboxConsole *gvir_sandbox_context_interactive_get_app_console(GVirSandboxContextInteractive *ctxt,
                                                                     GError **error);

G_END_DECLS

#endif /* __LIBVIRT_SANDBOX_CONTEXT_INTERACTIVE_H__ */
