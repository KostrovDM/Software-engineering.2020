﻿#pragma checksum "..\..\..\..\AdditionalContrils\AddPurchaseWindow.xaml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "07BF1CF881482CD351BC89FEB01A53BAEFBBBEED"
//------------------------------------------------------------------------------
// <auto-generated>
//     Этот код создан программой.
//     Исполняемая версия:4.0.30319.42000
//
//     Изменения в этом файле могут привести к неправильной работе и будут потеряны в случае
//     повторной генерации кода.
// </auto-generated>
//------------------------------------------------------------------------------

using ExpenceManager.AdditionalContrils;
using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Controls.Ribbon;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;


namespace ExpenceManager.AdditionalContrils {
    
    
    /// <summary>
    /// AddPurchaseWindow
    /// </summary>
    public partial class AddPurchaseWindow : System.Windows.Window, System.Windows.Markup.IComponentConnector {
        
        
        #line 16 "..\..\..\..\AdditionalContrils\AddPurchaseWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Grid MainGrid;
        
        #line default
        #line hidden
        
        
        #line 31 "..\..\..\..\AdditionalContrils\AddPurchaseWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.DataGrid GoodsDataGrid;
        
        #line default
        #line hidden
        
        
        #line 47 "..\..\..\..\AdditionalContrils\AddPurchaseWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Frame TheAddPageFrame;
        
        #line default
        #line hidden
        
        
        #line 63 "..\..\..\..\AdditionalContrils\AddPurchaseWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBlock TotalPriceTextBlock;
        
        #line default
        #line hidden
        
        
        #line 68 "..\..\..\..\AdditionalContrils\AddPurchaseWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button ConfirmButton;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.8.1.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/ExpenceManager;component/additionalcontrils/addpurchasewindow.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\..\..\AdditionalContrils\AddPurchaseWindow.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.8.1.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            this.MainGrid = ((System.Windows.Controls.Grid)(target));
            
            #line 19 "..\..\..\..\AdditionalContrils\AddPurchaseWindow.xaml"
            this.MainGrid.MouseDown += new System.Windows.Input.MouseButtonEventHandler(this.MainGrid_MouseDown);
            
            #line default
            #line hidden
            return;
            case 2:
            this.GoodsDataGrid = ((System.Windows.Controls.DataGrid)(target));
            return;
            case 3:
            this.TheAddPageFrame = ((System.Windows.Controls.Frame)(target));
            return;
            case 4:
            this.TotalPriceTextBlock = ((System.Windows.Controls.TextBlock)(target));
            return;
            case 5:
            this.ConfirmButton = ((System.Windows.Controls.Button)(target));
            
            #line 69 "..\..\..\..\AdditionalContrils\AddPurchaseWindow.xaml"
            this.ConfirmButton.Click += new System.Windows.RoutedEventHandler(this.ConfirmButton_Click);
            
            #line default
            #line hidden
            return;
            }
            this._contentLoaded = true;
        }
    }
}

