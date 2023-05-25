const tabItems=document.querySelectorAll('.tab-item');
const tabContentItems=document.querySelectorAll('.tab-content-item');


// Select tab content item
function selectItem(e) {
    removerBorder();
    removeShow();
    // Add border to current tab
    this.classList.add('tab-border');
    // Grab content item from the DOM
    console.log(this.id);
    const tabContentItem=document.querySelector(`#${this.id}-content`);
    // Add show class
    tabContentItem.classList.add('show');
}

function removerBorder() {
    tabItems.forEach(item => item.classList.remove('tab-border'));
}

function removeShow() {
    tabContentItems.forEach(item => item.classList.remove('show'));
}
// Listen for tab click
tabItems.forEach(item => item.addEventListener('click',selectItem));
